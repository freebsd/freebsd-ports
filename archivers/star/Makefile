PORTNAME=	star
CATEGORIES=	archivers

COMMENT=	Unique standard tape archiver with many enhancements

OPTIONS_DEFINE+=DOCS TARTEST
OPTIONS_SUB=	yes
TARTEST_DESC=	Install tartest and test scripts
TARTEST_VARS=	COMPONENTS+=tartest

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	mt \
		rmt \
		star \
		star_sym \
		strar

post-install-DOCS-off:
	${RM} ${STAGEDIR}share/doc/star/README*
	${RM} ${STAGEDIR}share/doc/star/STARvsGNUTAR

.include "${MASTERDIR}/Makefile.master"
