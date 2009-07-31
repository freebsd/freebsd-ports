# New ports collection makefile for:	sonata
# Date created:		2007-01-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sonata
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An elegant music player for MPD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk>=2.12.1:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk>=2.12.1:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_PKGNAMEPREFIX}mpd>=0.2.0:${PORTSDIR}/audio/py-mpd \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.82.4:${PORTSDIR}/devel/py-dbus

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Sonata

OPTIONS=	MPD	"Install Music Player Daemon" on \
		TAGLIB	"Install support for editing metadata" off \
		ZSI	"Install support for automatic lyrics fetching" off

REINPLACE_ARGS=	-i.bak -e 's,%%DOCSDIR%%,${DOCSDIR},'

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
.else
MAKE_ENV=	NO_INSTALL_MANPAGES=${NO_INSTALL_MANPAGES}
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=${NOPORTDOCS}
.endif

post-patch:
	@${REINPLACE_CMD} ${WRKSRC}/${PYSETUP}

.include <bsd.port.pre.mk>

.if defined (WITH_MPD)
RUN_DEPENDS+=	mpd:${PORTSDIR}/audio/musicpd
.endif

.if defined (WITH_TAGLIB)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tagpy>=0.94.5:${PORTSDIR}/audio/py-tagpy
.endif

.if defined (WITH_ZSI)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}zsi>=2.0,1:${PORTSDIR}/net/py-zsi
.endif

.include <bsd.port.post.mk>
