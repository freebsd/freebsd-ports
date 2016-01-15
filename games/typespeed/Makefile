# Created by: refugee
# $FreeBSD$

PORTNAME=	typespeed
PORTVERSION=	0.6.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test your typing speed and get your fingers' CPS

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-highscoredir="${SCOREDIR}"

SCOREDIR=	/var/games/typespeed
SCOREFILE=	typespeed.score

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -exec \
		${REINPLACE_CMD} -e 's|^\(CC =\).*|\1 @CC@|; \
			/chmod/ d; /chgrp/ d' {} \;
	@${REINPLACE_CMD} -e \
		's|\(/etc\)|${PREFIX}\1|' ${WRKSRC}/src/pathnames.h

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/convert \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-hs-conv
	${MV} ${STAGEDIR}${PREFIX}/etc/typespeedrc \
		${STAGEDIR}${PREFIX}/etc/typespeedrc.sample
	${MV} ${STAGEDIR}${SCOREDIR}/${SCOREFILE} \
		${STAGEDIR}${SCOREDIR}/${SCOREFILE}.sample

.include <bsd.port.mk>
