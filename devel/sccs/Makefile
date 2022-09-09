PORTNAME=	sccs
CATEGORIES=	devel

COMMENT=	Source Code Control System (SCCS)
WWW=		https://codeberg.org/schilytools/schilytools

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	patch \
		sccs

# these files are installed by the patch target,
# but they belong to sysutils/schilyutils
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/opatch
	${RM} ${STAGEDIR}${PREFIX}/bin/spatch
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/opatch.1
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/patch.1
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/spatch.1

.include "${MASTERDIR}/Makefile.master"
