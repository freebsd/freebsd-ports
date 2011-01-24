# New ports collection makefile for:	pmake
# Date created:		12 November 1998
# Whom:			steve
#
# $FreeBSD$
#

PORTNAME=	pmake
PORTVERSION=	2.1.37
CATEGORIES=	devel parallel
MASTER_SITES=	http://www.icsi.berkeley.edu/ftp/global/pub/speech/stolcke/software/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	steve
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The parallel make(1) program from the Sprite project

NO_CDROM=	Non-commercial use only

DEPRECATED=		does not build on any supported version of FreeBSD
EXPIRATION_DATE=	2011-02-23

WRKSRC=		${WRKDIR}/pmake
MAKEFILE=	makefile
ALL_TARGET=	pmake
PMAKE_ENV=	${MAKE_ENV} MAKE=${PREFIX}/bin/pmake
MAN1=		pmake.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
IGNORE=		does not support ${OPSYS}-${OSREL} at this time
.endif

post-patch:
	@${REINPLACE_CMD} '/memmove/d' ${WRKSRC}/lib/include/sprite.h

#
# Define this if you want to build and install with the 'customs'
# server support and the pmake to match.  Note, you'll still get
# the plain pmake in ${PREFIX}/bin/pmake.nocustoms.
#
#WANT_CUSTOMS=	yes

do-install::
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} install)

.if defined(WANT_CUSTOMS)
PLIST=		${PKGDIR}/pkg-plist.customs
MAN1+=		export.1 reginfo.1 rexport.1
MAN8=		cctrl.8 customs.8 importquota.8 logd.8

do-install::
	@(cd ${WRKSRC}; ${SETENV} ${PMAKE_ENV} ${PREFIX}/bin/pmake new; \
	  ${SETENV} ${PMAKE_ENV} ${PREFIX}/bin/pmake install)
	@${ECHO} "Adding customs service to /etc/services..."
	@${ECHO_CMD} -e 'customs\t\t8231/tcp\t# pmake customs server'>>/etc/services
	@${ECHO_CMD} -e 'customs\t\t8231/udp\t# pmake customs server'>>/etc/services
.else
do-install::
	@(cd ${WRKSRC}/doc; ${SETENV} ${PMAKE_ENV} ${MAKE})
	${INSTALL_MAN} ${WRKSRC}/doc/pmake.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
