# Ports collection makefile for:  raproxy
# Version required:     	  3.0b1
# Date created:			  Sat May 8, 1999
# Whom:				  Nick Sayer (nsayer@freebsd.org)
#
# $FreeBSD$
#

DISTNAME=	raproxy3.0b1
PKGNAME=	raproxy-3.0b1
CATEGORIES=	security net audio
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=     nsayer@freebsd.org

WRKSRC=		${WRKDIR}/raproxy

RESTRICTED=	"No redistribution allowed."

MAN8=		raproxy.8

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE='Please fill out the form at http://service.real.com/firewall/index.html and place the sources at ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} then run make again'
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raproxy ${PREFIX}/libexec/raproxy
	${INSTALL_MAN} ${WRKSRC}/raproxy.man ${PREFIX}/man/man8/raproxy.8

.include <bsd.port.post.mk>
