PORTNAME=	star
CATEGORIES=	archivers

COMMENT=	Unique standard tape archiver with many enhancements
WWW=		https://cdrtools.sourceforge.net/private/star.html

PORTDOCS=	README* STARvsGNUTAR

OPTIONS_DEFINE+=DOCS GNUTAR PROFILE
OPTIONS_SUB=	yes
GNUTAR_DESC=	Install a gnutar binary

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	libstreamar \
		mt \
		rmt \
		star \
		star_sym \
		strar

post-patch-PROFILE-off:
	@${ECHO_MSG} '=> Patching Makefiles to disable profiled libraries'
	@${REINPLACE_CMD} -e '/^MK_FILES/s, [a-z]*_p.mk,,' ${WRKSRC}/*/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/schily
	${INSTALL_DATA} ${WRKSRC}/include/schily/strar.h ${STAGEDIR}${PREFIX}/include/schily/
	# these are shipped in archivers/tartest
	${RM} -r ${STAGEDIR}${DOCSDIR}/testscripts

.include "${MASTERDIR}/Makefile.master"
