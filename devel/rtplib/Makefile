# New ports collection makefile for: 	rtplib
# Date created:		18 Jun 2002
# Whom:			Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	rtplib
PORTVERSION=	1.0b2
CATEGORIES=	devel mbone
MASTER_SITES=	http://www-out.bell-labs.com:80/project/RTPlib/

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A library for developing applications over RTP

RTP_HEADERS=	rtp_api.h rtp_highlevel.h rtp_lowlevel.h

RESTRICTED=	"Source recipient must acknowledge license"

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG = /usr/bin/printf 
IGNORE = :\n\
Due to licensing restrictions, you must fetch the sources to "${PORTNAME}" manually.\n\
Please place the tarball under \"${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}\".\n
.endif

pre-install:
.for header in ${RTP_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/include/${header}
.endfor
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/rtplib
	${INSTALL_DATA} ${WRKSRC}/rtp_api.html ${PREFIX}/share/doc/rtplib
.endif

.include <bsd.port.post.mk>
