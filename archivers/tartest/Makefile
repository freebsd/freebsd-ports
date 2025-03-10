PORTNAME=	tartest
CATEGORIES=	archivers devel

COMMENT=	Test tar archive for POSIX.1-1990 compliance
WWW=		https://codeberg.org/schilytools/schilytools

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	tartest

post-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/doc/star
	cd ${WRKSRC}/star && ${COPYTREE_SHARE} testscripts ${STAGEDIR}/${PREFIX}/share/doc/star/

.include "${MASTERDIR}/Makefile.master"
