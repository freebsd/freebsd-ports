PORTREVISION=	3
PKGNAMESUFFIX=	-qt5

COMMENT=	Qt5 bindings to AppStream

SUBPACKAGES=

LIB_DEPENDS=	libappstream.so:devel/appstream

QT_FLAVOR=	5

MASTERDIR=	${.CURDIR}/../appstream
PLIST=		${.CURDIR}/pkg-plist

post-install:
	# remove files belonging to the master port
	${SED} -e 's|@@compose@@||' -e 's|@@qt6@@||' ${MASTERDIR}/pkg-plist \
		| ${XARGS} -L 1 -I % ${RM} -rf ${STAGEDIR}${PREFIX}/%
	${FIND} ${STAGEDIR}${PREFIX} -empty -delete
	${RM} -rf ${STAGEDIR}${PREFIX}/etc ${STAGEDIR}${PREFIX}/share/man

.include	"${MASTERDIR}/Makefile"
