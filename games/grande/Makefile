# New ports collection makefile for:   grande
# Date created:        20 Feb 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grande
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://kxl.hn.org/download/
DISTNAME=	${PORTNAME}-KXL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Zanac type game

BUILD_DEPENDS=	${X11BASE}/lib/libKXL-1.1.7.so:${PORTSDIR}/devel/kxl
RUN_DEPENDS=	${X11BASE}/lib/libKXL-1.1.7.so:${PORTSDIR}/devel/kxl

NO_CDROM=	Possible copyright infringement

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|^inst_path=.*$$|inst_path="$${datadir}/grande"|g ; \
		 s|^score_path=.*$$|score_path="$${datadir}/grande/score"|g' \
			${WRKSRC}/configure

pre-install:
	@${MKDIR} ${DATADIR}/score

.include <bsd.port.mk>
