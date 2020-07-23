# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	arj
PORTVERSION=	3.10.22
PORTREVISION=	8
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.78_3.10%20build%2022:source \
		DEBIAN_POOL:patch
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:source \
		${PORTNAME}_${PORTVERSION}-23.debian.tar.xz:patch

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open source implementation of the ARJ archiver

LICENSE=	GPLv2

IGNORE_PATCHES=	002_no_remove_static_const.patch  \
		doc_refer_robert_k_jung.patch \
		gnu_build_cross.patch \
		gnu_build_fix.patch \
		gnu_build_flags.patch \
		gnu_build_pie.patch \
		gnu_build_strip.patch \
		hurd_no_fcntl_getlk.patch \
		reproducible_help_archive.patch

USES=		alias autoreconf gmake

EXTRA_PATCHES=	${WRKDIR}/debian/patches/*.patch
PATCH_STRIP=	-p1

PORTSCOUT=	skipv:3.10g

GNU_CONFIGURE=	yes
AUTORECONF_WRKSRC=	${WRKSRC}/gnu
CONFIGURE_WRKSRC=	${WRKSRC}/gnu
MAKEFILE=	GNUmakefile
ALL_TARGET=	prepare all
STRIP=		# empty
LLD_UNSAFE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	LOCALE
OPTIONS_SINGLE_LOCALE=	LOCALE_DE LOCALE_EN LOCALE_RU
OPTIONS_DEFAULT=LOCALE_EN
LOCALE_DESC=	Select language to define at build time
LOCALE_DE_DESC=	German
LOCALE_EN_DESC=	English
LOCALE_RU_DESC=	Russian
LOCALE_DE_MAKE_ARGS=	LOCALE=de
LOCALE_EN_MAKE_ARGS=	LOCALE=en
LOCALE_RU_MAKE_ARGS=	LOCALE=ru

pre-patch:
	@${RM} ${IGNORE_PATCHES:S,^,${WRKDIR}/debian/patches/,}

post-patch:
	@${REINPLACE_CMD} -e 's!/etc!${LOCALBASE}/etc!' \
		 ${WRKSRC}/arj.c ${WRKSRC}/file_reg.c ${WRKSRC}/rearj.c
	@${REINPLACE_CMD} -e 's!-O2!!' -e 's!ALIGN_POINTERS!&,1,desc!' \
		-e 's!USE_COLORS!&,1,desc!' ${WRKSRC}/gnu/configure.in
	@${REINPLACE_CMD} -e 's!^static !!' ${WRKSRC}/integr.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} COPYING debug.txt \
		${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/resource/en && ${INSTALL_DATA} arjl.txt arjs.txt \
		history.txt readme.txt unix.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
