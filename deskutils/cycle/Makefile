# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cycle
PORTVERSION=	0.3.1
PORTREVISION=	11
CATEGORIES=	deskutils biology python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calendar program for women

LICENSE=	GPLv2+

USES=		python:2.7,run shebangfix tar:bzip2
SHEBANG_FILES=	cycle.py
USE_WX=		3.0+
WX_COMPS=	python
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,"msg","${PREFIX}/share/locale",' \
		-e 's,"","${DOCSDIR}", ; s,"icons","${DATADIR}/icons",' \
		-e 's,"bitmaps","${DATADIR}/bitmaps",' ${WRKSRC}/set_dir.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC} && ${INSTALL_DATA} cal_year.py dialogs.py p_rotor.py \
		save_load.py set_dir.py setup.py \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	@${MKDIR} ${STAGEDIR}${DATADIR}/bitmaps \
		${STAGEDIR}${DATADIR}/icons/mini \
		${STAGEDIR}${DATADIR}/icons/large
	${INSTALL_DATA} ${WRKSRC}/bitmaps/*.[pb]* ${STAGEDIR}${DATADIR}/bitmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/mini/*.xpm \
		${STAGEDIR}${DATADIR}/icons/mini
	${INSTALL_DATA} ${WRKSRC}/icons/large/*.xpm \
		${STAGEDIR}${DATADIR}/icons/large
# These locale directories are not part of mtree(8) template yet
.for l in ca cs gl sk
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${l}/LC_MESSAGES
.endfor
.for l in ca cs de es gl ru sk
	${INSTALL_DATA} ${WRKSRC}/msg/${l}/LC_MESSAGES/${PORTNAME}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${l}/LC_MESSAGES
.endfor
# Docs are kind of mandatory here since they are used as internal help
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
