# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	arj
PORTVERSION=	3.10.22
PORTREVISION=	5
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.78_3.10%20build%2022:source \
		DEBIAN_POOL:patch
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:source \
		${PORTNAME}_${PORTVERSION}-16.debian.tar.xz:patch

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open source implementation of the ARJ archiver

LICENSE=	GPLv2

PORTSCOUT=	skipv:3.10g

EXTRA_PATCHES=	${WRKDIR}/debian/patches/*.patch
IGNORE_PATCHES=	002_no_remove_static_const.patch  \
		doc_refer_robert_k_jung.patch \
		gnu_build_cross.patch \
		gnu_build_fix.patch \
		gnu_build_flags.patch \
		gnu_build_pie.patch \
		gnu_build_strip.patch \
		hurd_no_fcntl_getlk.patch
PATCH_STRIP=	-p1

USES=		alias gmake
USE_AUTOTOOLS=	autoconf
CONFIGURE_WRKSRC=	${WRKSRC}/gnu
MAKEFILE=	GNUmakefile
MAKE_ARGS=	LOCALE="${LANGUAGE}"
ALL_TARGET=	prepare all
STRIP=		# empty

CFLAGS+=	-fPIC
LANGUAGE?=	en

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${RM} ${IGNORE_PATCHES:S,^,${WRKDIR}/debian/patches/,}

post-patch:
	@${REINPLACE_CMD} -e 's!/etc!${LOCALBASE}/etc!' \
		 ${WRKSRC}/arj.c ${WRKSRC}/file_reg.c ${WRKSRC}/rearj.c
	@${REINPLACE_CMD} -e 's!-O2!!' ${WRKSRC}/gnu/configure.in
	@${REINPLACE_CMD} -e 's!^static !!' ${WRKSRC}/integr.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} COPYING debug.txt \
		${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/resource/en && ${INSTALL_DATA} arjl.txt arjs.txt \
		history.txt readme.txt unix.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
