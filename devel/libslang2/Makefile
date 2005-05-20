# New ports collection makefile for:	libslang2
# Date created:		2005-05-16
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	libslang2
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v2.0/
DISTNAME=	slang-${PORTVERSION}

MAINTAINER=	freebsd@galle.com.br
COMMENT=	Routines for rapid alpha-numeric terminal applications development

USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFLICTS=	libslang-1.*

ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf

MAN1=		slsh.1
DOCSDIR=	${PREFIX}/share/doc/slang

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
PLIST_SUB+=	PCRE=""
.else
CONFIGURE_ARGS+=	--disable-pcre
PLIST_SUB+=	PCRE="@comment "
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--disable-png
PLIST_SUB+=	PNG="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, install_docs,,g' ${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.post.mk>
