#!/bin/sh -f

RUNTIME_FILES=" components/libabsyncsvc.so components/libaddrbook.so \
		components/libmork.so components/libmozldap.so \
		components/libnecko.so components/libprofile.so \
		components/librdf.so components/libstrres.so \
		components/libunicharutil.so components/libuconv.so \
		components/libucvcn.so components/libucvibm.so \
		components/libucvja.so components/libucvko.so \
		components/libucvlatin.so components/libucvtw.so \
		components/libucvtw2.so components/liburiloader.so \
		components/libvcard.so components/libxpconnect.so \
		components/libpref.so components/libchrome.so libmozjs.so \
		libmsgbaseutil.so libldap50.so libnspr4.so libplc4.so \
		libplds4.so libxpcom.so libmozz.so component.reg \
		components/necko_dns.xpt components/xpcom_xpti.xpt \
		components/xpcom_threads.xpt components/xpcom_io.xpt \
		components/xpcom_ds.xpt components/xpcom_components.xpt \
		components/xpcom_base.xpt components/xpti.dat \
		defaults/pref/all.js defaults/pref/config.js \
		defaults/pref/editor.js defaults/pref/initpref.js \
		defaults/pref/inspector.js defaults/pref/mailnews.js \
		defaults/pref/security-prefs.js defaults/pref/unix.js \
		defaults/pref/xpinstall.js"

LIB_FILES="	lib/libembed_base_s.a lib/libmozreg_s.a \
		lib/libnspr4.so lib/libxpcom.so lib/libprldap50.so"

INC_FILES="include/"
INC_FILES2="public/"

if [ $# -lt 2 -o $# -gt 3 ] ; then
	echo 
	echo usage: $0 mozilla_dist target [target_dir]
	echo
	echo where:
	echo
	echo "mozilla_dist points to the mozilla distribution"
	echo "target concatenates  OS, compiler and CPU (e.g. FREEBSDGCCI etc)"
	echo "target_dir is the directory to place the zips"
	exit 1
fi

MOZ_DIST=$1
TARGET=$2
if [ "w$3" != "w" ]; then
	TARGET_DIR=$3
else
	if [ "w$TARGET_DIR" == "w" ]; then
		TARGET_DIR=
	fi
fi

ZIP_TARGET=$TARGET_DIR
if [ -z "$ZIP_TARGET" ] ; then
	ZIP_TARGET=../
fi

# just to remember the current working directory
STARTING_DIR=`pwd`

echo
echo --- creating zips for $TARGET, using mozilla distribution in $MOZ_DIST

# Create the directories
[ ! -d $TARGET_DIR/$TARGET/runtime ] && mkdir -p $TARGET_DIR/$TARGET/runtime
[ ! -d $TARGET_DIR/$TARGET/runtime/components ] && mkdir -p $TARGET_DIR/$TARGET/runtime/components
[ ! -d $TARGET_DIR/$TARGET/runtime/defaults ] && mkdir -p $TARGET_DIR/$TARGET/runtime/defaults
[ ! -d $TARGET_DIR/$TARGET/runtime/defaults/pref ] && mkdir -p $TARGET_DIR/$TARGET/runtime/defaults/pref
[ ! -d $TARGET_DIR/$TARGET/lib ] && mkdir -p $TARGET_DIR/$TARGET/lib
[ ! -d $TARGET_DIR/$TARGET/inc ] && mkdir -p $TARGET_DIR/$TARGET/inc
[ ! -d $TARGET_DIR/$TARGET/inc/nspr ] && mkdir -p $TARGET_DIR/$TARGET/inc/nspr
[ ! -d $TARGET_DIR/$TARGET/inc/obsolete ] && mkdir -p $TARGET_DIR/$TARGET/inc/obsolete

# Copy the files
echo
echo --- copying files
echo

for i in $RUNTIME_FILES; do
	if [ ! -f $MOZ_DIST/bin/$i ]; then
		echo $MOZ_DIST/bin/$i does not exist, check your distribution
	else
		if [ `echo $i | grep component` ]; then
			cp $MOZ_DIST/bin/$i $TARGET_DIR/$TARGET/runtime/components/
		elif [ `echo $i | grep defaults` ]; then
			cp $MOZ_DIST/bin/$i $TARGET_DIR/$TARGET/runtime/defaults/pref/
		else
			cp $MOZ_DIST/bin/$i $TARGET_DIR/$TARGET/runtime/
		fi
	fi
done

for i in $LIB_FILES; do
	if [ ! -f $MOZ_DIST/$i ]; then
		echo $MOZ_DIST/$i does not exist, check your distribution
	else
		cp -R -L $MOZ_DIST/$i $TARGET_DIR/$TARGET/lib/
	fi
done

for i in `ls -1 $MOZ_DIST/$INC_FILES`; do
	if [ ! -d $i ]; then 
		cp -R -L $MOZ_DIST/include/$i $TARGET_DIR/$TARGET/inc/
	fi
done

for i in `ls -1 $MOZ_DIST/$INC_FILES2`; do
        if [ ! -d $i ]; then
		cp -R -L $MOZ_DIST/public/$i $TARGET_DIR/$TARGET/inc
	fi
done

for i in `ls -1 $MOZ_DIST/$INC_FILES/nspr`; do
        if [ ! -d $i ]; then
		cp -R -L $MOZ_DIST/include/nspr/$i $TARGET_DIR/$TARGET/inc/nspr
	fi
done

for i in `ls -1 $MOZ_DIST/$INC_FILES/nspr/obsolete`; do
        if [ ! -d $i ]; then
		cp -R -L $MOZ_DIST/include/nspr/obsolete/$i $TARGET_DIR/$TARGET/inc/obsolete
	fi
done

# delete old zips

[ -f $TARGET_DIR/$TARGET/runtime.zip ] && rm -f $TARGET_DIR/$TARGET/runtime.zip
[ -f $TARGET_DIR/$TARGET/lib.zip ] && rm -f $TARGET_DIR/$TARGET/lib.zip
[ -f $TARGET_DIR/$TARGET/inc.zip ] && rm -f $TARGET_DIR/$TARGET/inc.zip

# zip the runtime files

echo
echo --- creating ${TARGET}runtime.zip
echo

cd $TARGET_DIR/$TARGET/runtime
find . -type f | zip $ZIP_TARGET/${TARGET}runtime.zip -@

# zip the lib files
echo 
echo --- creating ${TARGET}lib.zip
echo 

cd $TARGET_DIR/$TARGET/lib
find . -type f | zip $ZIP_TARGET/${TARGET}lib.zip -@

# zip the inc files
echo
echo --- creating ${TARGET}inc.zip
echo

cd $TARGET_DIR/$TARGET/inc
find . -type f | zip $ZIP_TARGET/${TARGET}inc.zip -@

# remove dirs
cd $STARTING_DIR
rm -rf $TARGET_DIR/$TARGET

echo
echo --- done
echo

