# New ports collection makefile for:	q-audio
# Date created:		14 August 2003
# Whom:			ag@muwiinfa.geschichte.uni-mainz.de Albert Graef
#
# $FreeBSD$
#

PORTNAME=	audio
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	q-lang
PKGNAMEPREFIX=	q-
DISTNAME=	${PKGNAME}

MAINTAINER=	ag@muwiinfa.geschichte.uni-mainz.de
COMMENT=	Q-Audio -- digital audio interface for the Q language

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		q.4:${PORTSDIR}/lang/q

USE_REINPLACE=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pthread="${PTHREAD_LIBS}"
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

DATADIR=	${PREFIX}/share/q
EXAMPLESDIR=	${PREFIX}/share/examples/q/audio

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${GREP} -l "^examplesdir" | ${XARGS} ${REINPLACE_CMD} -e \
		"s;[(]pkgdatadir[)]/examples;(datadir)/examples/q;"

.include <bsd.port.mk>
