# New ports collection makefile for:	motor
# Date created:				20 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	motor
PORTVERSION=	3.2.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A powerful text mode based programming IDE

USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USE_REINPLACE=	yes

MAN1=		motor.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
	@${REINPLACE_CMD} -e '/_G_config.h/d' 		\
		${WRKSRC}/kkstrtext/conf.h		\
		${WRKSRC}/kksystr/include/conf.h	\
		${WRKSRC}/kkconsui/include/conf.h

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} FAQ README ${DOCSDIR})
.endif

.include <bsd.port.post.mk>

