# New ports collection makefile for:	jtag
# Date created:		2006-08-05
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	jtag
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/openwince/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to work with JTAG-aware boards

BUILD_DEPENDS=	${OPENWINCE_INCLUDE_DEP}:${PORTSDIR}/devel/openwince-include
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

ONLY_FOR_ARCHS=	i386
OPENWINCE_INCLUDE=${LOCALBASE}/include/openwince
OPENWINCE_INCLUDE_DEP=${OPENWINCE_INCLUDE}/common.h

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
.endif

post-extract:
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/include/openwince,${OPENWINCE_INCLUDE}," \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO \
		${WRKSRC}/doc/internals.xml ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
