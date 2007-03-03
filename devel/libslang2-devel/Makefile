# New ports collection makefile for:	libslang2-devel
# Date created:		2007-02-24
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	libslang2
PORTVERSION=	20070224
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	garga/slang
PKGNAMESUFFIX=	-devel
DISTNAME=	slang2${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Routines for rapid alpha-numeric terminal applications development

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFLICTS=	libslang-1.*

ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf

MAN1=		slsh.1
DOCSDIR=	${PREFIX}/share/doc/slang
DATADIR=	${PREFIX}/share/slsh

OPTIONS=	PCRE "Include pcre support" on \
		PNG  "Include png support"  on

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
PLIST_SUB+=	PCRE=""
.else
CONFIGURE_ARGS+=	--without-pcre
PLIST_SUB+=	PCRE="@comment "
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=	PNG="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, install_docs,,g' ${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.post.mk>
