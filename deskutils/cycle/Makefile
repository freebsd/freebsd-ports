# New ports collection makefile for:	Cycle
# Date created:				30 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cycle
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	deskutils biology python
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A calendar program for women

USE_BZIP2=	yes
USE_PYTHON_RUN=	yes
USE_WX=		2.6
WX_COMPS=	python
NO_BUILD=	yes

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's,"msg","${PREFIX}/share/locale",' \
		-e 's,"","${DOCSDIR}", ; s,"icons","${DATADIR}/icons",' \
		-e 's,"bitmaps","${DATADIR}/bitmaps",' ${WRKSRC}/set_dir.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/cal_year.py ${WRKSRC}/dialogs.py \
		${WRKSRC}/p_rotor.py ${WRKSRC}/save_load.py \
		${WRKSRC}/set_dir.py ${WRKSRC}/setup.py ${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${DATADIR}/bitmaps ${DATADIR}/icons/mini ${DATADIR}/icons/large
	${INSTALL_DATA} ${WRKSRC}/bitmaps/*.[pb]* ${DATADIR}/bitmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/mini/*.xpm ${DATADIR}/icons/mini
	${INSTALL_DATA} ${WRKSRC}/icons/large/*.xpm ${DATADIR}/icons/large
	# These locales are not in mtree yet
.for l in ca cs gl sk
	@${MKDIR} ${PREFIX}/share/locale/${l}/LC_MESSAGES
.endfor
.for l in ca cs de es gl ru sk
	${INSTALL_DATA} ${WRKSRC}/msg/${l}/LC_MESSAGES/${PORTNAME}.mo \
		${PREFIX}/share/locale/${l}/LC_MESSAGES
.endfor
	# Docs are kinda mandatory here since being used as internal help
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README*.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
