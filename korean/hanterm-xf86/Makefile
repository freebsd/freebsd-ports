# New ports collection makefile for:	hanterm-xf86
# Date created:		22 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	19
CATEGORIES=	korean x11
MASTER_SITES=	http://www.kr.FreeBSD.org/~hwang/hanterm/ \
		http://hanterm.org/download/hanterm-xf/
PKGNAMESUFFIX=	-xf
DISTNAME=	hanterm${PKGNAMESUFFIX}-p${PORTVERSION}

MAINTAINER=	cjh@FreeBSD.org

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-16-color
CONFIGURE_ENV+=		LIBS="${LDFLAGS} -L${LOCALBASE}/lib -liconv" \
			CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
NO_INSTALL_MANPAGES=	yes

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Hanterm.ad \
			 ${PREFIX}/lib/X11/app-defaults/Hanterm
	${MKDIR} ${PREFIX}/share/doc/hanterm-xf
	${INSTALL_DATA} ${WRKSRC}/hanterm-doc/README.xf \
			${PREFIX}/share/doc/hanterm-xf
	${INSTALL_DATA} ${WRKSRC}/hanterm-doc/README.xf.old \
			${PREFIX}/share/doc/hanterm-xf

.include <bsd.port.mk>
