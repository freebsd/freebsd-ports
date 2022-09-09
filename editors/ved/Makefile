PORTNAME=	ved
CATEGORIES=	editors

COMMENT=	Visual editor (easy to learn, fast, and lean)
WWW=		https://codeberg.org/schilytools/schilytools

OPTIONS_DEFINE=	DOCS

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	ved

post-install-DOCS-off:
	${RM} ${STAGEDIR}share/doc/vedsheet.*
	${RM} ${STAGEDIR}share/man/help/ved.help.gz

.include "${MASTERDIR}/Makefile.master"
