# New ports collection makefile for:    tksol
# Date created:         26 June 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tksol
PORTVERSION=	1.4
CATEGORIES=	games tk82
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/games/solitaires/ \
		http://www.gtlib.cc.gatech.edu/pub/linux/games/solitaires/ \
		http://ftp.fi.muni.cz/pub/linux/metalab.unc.edu/games/solitaires/ \
		ftp://metalab.unc.edu/pub/linux/games/solitaires/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A version of the card game solitaire

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
NO_BUILD=	yes
MAN6=		tksol.6
MANCOMPRESSED=	yes

TKSOLDIR=	${PREFIX}/share/games/tksol

post-extract:
	@${RM} -rf ${WRKSRC}/downbitmaps/.xvpics

post-patch:
	@${REINPLACE_CMD} -e "s;/usr/bin/wish;${PREFIX}/bin/wish8.4;" \
		-e "s;/usr/local/lib/tksol;${TKSOLDIR};g" \
		 ${WRKSRC}/tksol

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tksol ${PREFIX}/bin
	${MKDIR} ${TKSOLDIR}
.for dir in cardbitmaps downbitmaps pictures
	cd ${WRKSRC}; tar -cpf - ${dir} | \
		(cd ${TKSOLDIR}; tar -xpf -)
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MAN6}.gz ${PREFIX}/man/man6

.include <bsd.port.mk>
