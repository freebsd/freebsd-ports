# ex:ts=8
# Ports collection makefile for:	cvsd
# Date Created:			Dec 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsd
PORTVERSION=	0.9.14
CATEGORIES=	devel
MASTER_SITES=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN5=	cvsd.conf.5
MAN8=	cvsd.8 cvsd-buildroot.8 cvsd-passwd.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|@ACLOCAL@|${TRUE}|g ; \
		 s|@AUTOCONF@|${TRUE}|g ; \
		 s|@AUTOMAKE@|${TRUE}|g ; \
		 s|@AUTOHEADER@|${TRUE}|g ; \
		 s|init.d/cvsd|rc.d/cvsd.sh.sample|g ; \
		 s|init.d|rc.d|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
