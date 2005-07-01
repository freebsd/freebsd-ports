# New ports collection makefile for:	Cycle
# Date created:				30 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cycle
PORTVERSION=	0.3.0
CATEGORIES=	deskutils biology python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A calendar program for women

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wx-2.6-gtk2-ansi/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26

USE_BZIP2=	yes
USE_PYTHON_RUN=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's,"msg","${PREFIX}/share/locale",' \
		-e 's,"","${DOCSDIR}", ; s,"icons","${DATADIR}/icons",' \
		-e '$$s,^$$,bitmaps_dir="${DATADIR}/bitmaps",' \
		${WRKSRC}/set_dir.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/cal_year.py ${WRKSRC}/dialogs.py \
		${FILESDIR}/p_rotor.py ${WRKSRC}/save_load.py \
		${WRKSRC}/set_dir.py ${WRKSRC}/setup.py ${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${DATADIR}/bitmaps ${DATADIR}/icons/mini ${DATADIR}/icons/large
	${INSTALL_DATA} ${WRKSRC}/bitmaps/*.[pb]* ${DATADIR}/bitmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/mini/*.xpm ${DATADIR}/icons/mini
	${INSTALL_DATA} ${WRKSRC}/icons/large/*.xpm ${DATADIR}/icons/large
	# These two (cs, sk) are not in mtree yet
	@${MKDIR} ${PREFIX}/share/locale/cs/LC_MESSAGES \
		${PREFIX}/share/locale/sk/LC_MESSAGES
.for l in cs de ru sk
	${INSTALL_DATA} ${WRKSRC}/msg/${l}/LC_MESSAGES/${PORTNAME}.mo \
		${PREFIX}/share/locale/${l}/LC_MESSAGES
.endfor
	# Docs are kinda mandatory here since being used as internal help
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README*.html ${DOCSDIR}
	${INSTALL_MAN} ${FILESDIR}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
