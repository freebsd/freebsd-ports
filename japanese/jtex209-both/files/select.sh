#!/bin/sh
# Usage: select.sh ${FILESDIR} ${DISTDIR} ${PKGDIR} [ASCII|NTT|BOTH|SELECT]

if [ "$4" = "BOTH" ]; then
        CHOICE=both
        BATCH=BATCH
	echo "Batch mode compile ASCII jtex1.7-p1.0.9F and NTT jtex-1.52."
elif [ "$4" = "ASCII" ]; then
        CHOICE=1
        BATCH=BATCH
	echo "Batch mode compile ASCII jtex1.7-p1.0.9F."
elif [ "$4" = "NTT" ]; then
        CHOICE=2
        BATCH=BATCH
	echo "Batch mode compile NTT jtex1.52."
else
	echo "Which jtex do you like to install?"
	echo "1. Install ASCII jtex1.7-p1.0.9F only."
	echo "2. Install NTT jtex-1.52 only."
	echo "3. Install both of them (default)." 
	read CHOICE 
fi
case ${CHOICE} in
	1)
	 echo "Install ASCII jtex1.7-p1.0.9F only." ;
	 echo
	 cp $1/ascii-makefile ./Makefile
	 $1/ascii-setup.sh $1 $2 ${BATCH}
	;;
	2)
	 echo "Install NTT jtex-1.52 only."
	 echo
	 cp $1/ntt-makefile ./Makefile
	 $1/ntt-setup.sh $1 $2 ${BATCH}
	;;
	*) 
	 echo "Install both of them." 
	 echo
	 cp $1/both-makefile ./Makefile
	 cp $1/linkselect.sh .
	 $1/ntt-setup.sh $1 $2 ${BATCH}
	 $1/ascii-setup.sh $1 $2 ${BATCH}
;;
esac 
