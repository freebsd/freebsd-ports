# ex:ts=8
# Ports collection makefile for:    conserver
# Date created:         22 November 1997
# Whom:                 Peter Wemm <peter@netplex.com.au>
#
# $FreeBSD$
#

PORTNAME=	conserver
PORTVERSION=	8.5
PORTREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.physics.purdue.edu/pub/pundits/ \
		http://www.komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Manage remote serial consoles via TCP/IP

DEPRECATED=	Depends on devel/msrc0, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

BUILD_DEPENDS=	makeme:${PORTSDIR}/devel/msrc0 \
		mkcmd:${PORTSDIR}/devel/mkcmd

MAN5=		conserver.cf.5
MAN8=		autologin.8 console.8 conserver.8

# Set this to where you want console(8) to connect to by default
# or use something like ``make DEFAULTHOST=myserver.mydomain.net''
DEFAULTHOST?=	localhost
DEFAULTPORT?=	782
MAKE_ENV+=	DEFAULTHOST="${DEFAULTHOST}" DEFAULTPORT="${DEFAULTPORT}"
#PKGMESSAGE=	${WRKDIR}/MESSAGE
USE_RC_SUBR=	conserver.sh

do-build:
	${REINPLACE_CMD} -e 's:/usr/local/lib:${PREFIX}/etc:g'  \
	    ${WRKSRC}/etc/conserver/cons.h
.for d in etc/conserver etc/console etc/autologin
	(cd ${WRKSRC}/$d && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_ARGS} ${ALL_TARGET})
.endfor
	#@${SED} -e 's:/usr/local:${PREFIX}:g'  \
	#    ${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
.for d in etc/conserver etc/console etc/autologin
	@(cd ${WRKSRC}/$d && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	@${INSTALL_DATA} ${WRKSRC}/lib/conserver.cf/conserver.cf \
	    ${PREFIX}/etc/conserver.cf.eg
	@${SED} -e 's:/usr/local/lib:${PREFIX}/etc:g'  \
	    ${WRKSRC}/lib/conserver.cf/conserver.cf.man  \
	    > ${PREFIX}/man/man5/conserver.cf.5
	@${SED} -e 's:/usr/local/etc:${PREFIX}/sbin:g'  \
	    ${WRKSRC}/etc/autologin/autologin.man  \
	    > ${PREFIX}/man/man8/autologin.8
	@${SED} -e 's:/usr/local/lib:${PREFIX}/etc:g'  \
	    ${WRKSRC}/etc/conserver/conserver.man  \
	    > ${PREFIX}/man/man8/conserver.8
	@${SED} -e 's:console\.itsd\.fedex\.com:${DEFAULTHOST}:g'  \
	    ${WRKSRC}/etc/console/console.man  \
	    > ${PREFIX}/man/man8/console.8
	@${CHMOD} 0444 ${PREFIX}/man/man5/conserver.cf.5  \
	    ${PREFIX}/man/man8/autologin.8  \
	    ${PREFIX}/man/man8/conserver.8  \
	    ${PREFIX}/man/man8/console.8
	@#	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
