# ex:ts=8
# Ports collection makefile for:	cvsd
# Date Created:			Dec 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsd
PORTVERSION=	0.9.6
CATEGORIES=	devel
MASTER_SITES=	http://tiefighter.et.tudelft.nl/~arthur/cvsd/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN5=	cvsd.conf.5
MAN8=	cvsd.8 cvsd-buildroot.8 cvsd-passwd.8

post-patch:
	@${PERL} -pi -e 's|init.d/cvsd|rc.d/cvsd.sh|g ; \
		 s|init.d|rc.d|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
