# $FreeBSD$

PORTNAME=	xcwcp
COMMENT=	X11 CW Tutor using unixcw

LIB_DEPENDS=	libcw.so:${PORTSDIR}/comms/unixcw

MASTERDIR=	${.CURDIR}/../unixcw

PLIST=		${.CURDIR}/pkg-plist
USE_QT4=	gui moc_build qmake_build rcc_build uic_build designer
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--enable-xcwcp
PLIST_FILES=	bin/xcwcp \
		man/man1/xcwcp.1.gz

post-stage:
	# Remove files from the unixcw plist
	for plistfile in `cat ${MASTERDIR}/pkg-plist`; \
	do \
		cleanfile=`echo $${plistfile} | ${SED} -E 's|man/man(.*).gz|man/man\1|'`; \
		${RM} ${STAGEDIR}${PREFIX}/$${cleanfile}; \
	done

.include "${MASTERDIR}/Makefile"
