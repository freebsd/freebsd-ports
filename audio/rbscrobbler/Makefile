# New ports collection Makefile for:	rbscrobbler
# Date created:				2005-01-30
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	rbscrobbler
PORTVERSION=	0.0.9
CATEGORIES=	audio gnome
MASTER_SITES=	http://members.cox.net/alexrevo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rhythmbox plugin for Audioscrobbler

RUN_DEPENDS=	rhythmbox:${PORTSDIR}/audio/rhythmbox

USE_GNOME=	pygnomeextras
USE_PYTHON=	yes
USE_REINPLACE=	yes

MAN1=		rbscrobbler.1

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|CFLAGS =|CFLAGS +=|g ; \
		 s|/usr/include/python2.3/|${PYTHON_INCLUDEDIR}|g'

do-install:
	${INSTALL_MAN} ${WRKSRC}/rbscrobbler.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/rbscrobbler
	${INSTALL_SCRIPT} ${WRKSRC}/rbscrobbler.py \
		${PYTHONPREFIX_SITELIBDIR}/rbscrobbler
	${LN} -sf ${PYTHONPREFIX_SITELIBDIR}/rbscrobbler/rbscrobbler.py \
		${PREFIX}/bin/rbscrobbler
.for file in Audioscrobbler.py Debug.py MyQueue.py Rhythmbox_Bonobo.py \
	Scrobbler_Musicbrainz.py singletonmixin.py
	${INSTALL_DATA} ${WRKSRC}/${file} \
		${PYTHONPREFIX_SITELIBDIR}/rbscrobbler
.endfor
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/rbscrobbler/images
	${INSTALL_DATA} ${WRKSRC}/images/*.png \
		${PYTHONPREFIX_SITELIBDIR}/rbscrobbler/images
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/rbscrobbler/trayicon
.for file in trayicon/__init__.py trayicon/trayicon.so
	${INSTALL_DATA} ${WRKSRC}/${file} \
		${PYTHONPREFIX_SITELIBDIR}/rbscrobbler/trayicon
.endfor

.include <bsd.port.mk>
