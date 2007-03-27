# New ports collection makefile for:	jtag
# Date created:		2006-08-05
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	jtag
PORTVERSION=	0.5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=openwince

MAINTAINER=	stas@FreeBSD.org
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

#
# We haven't this on FreeBSD version prior to 5.1
#
.if ${OSVERSION} < 501000
CFLAGS+=	-Duseconds_t=long
.endif

.if ${OSVERSION} < 500000 || exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
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
