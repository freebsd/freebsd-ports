# ex:ts=8
# Ports collection makefile for:	cvsd
# Date Created:			Dec 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsd
PORTVERSION=	0.9.3
CATEGORIES=	devel
MASTER_SITES=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/

MAINTAINER=	porst@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"

MAN5=	cvsd.conf.5
MAN8=	cvsd.8 cvsd-buildroot.8 cvsd-passwd.8

post-patch:
	@${PERL} -pi -e "s|init.d|rc.d|g" ${WRKSRC}/Makefile.in

post-install:
	@${MV} ${PREFIX}/etc/rc.d/cvsd ${PREFIX}/etc/rc.d/cvsd.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
