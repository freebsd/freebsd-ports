# ex:ts=8
# Ports collection makefile for:    conserver
# Date created:         22 November 1997
# Whom:                 Peter Wemm <peter@netplex.com.au>
#
# $FreeBSD$
#

PORTNAME=	conserver
PORTVERSION=	5.21b
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.uu.net/vendor/bitsko/config-mgmt/ \
		ftp://unix.hensa.ac.uk/mirrors/uunet/vendor/bitsko/config-mgmt/
DISTNAME=	${PORTNAME}-5.21-Beta
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	obrien@FreeBSD.org

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
MAN5=		conserver.cf.5
MAN8=		console.8 conserver.8

# Set this to where you want console(8) to connect to by default
# or use something like ``make DEFAULTHOST=myserver.mydomain.net''
DEFAULTHOST?=	localhost
MAKE_ENV+=	DEFAULTHOST="${DEFAULTHOST}"

# XXX we also have to work around ``new'' uudecode behavior, thanks guys!
post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
.if !exists(${WRKSRC}/group.c)
	@${MV} ${WRKSRC}/group.c ${WRKSRC}/conserver/group.c
.endif

post-install:
.if !exists(${PREFIX}/etc/rc.d/conserver.sh)
	@${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/conserver.sh startup file."
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/conserver.sh ${PREFIX}/etc/rc.d
.endif

.include <bsd.port.mk>
