# New ports collection makefile for:	gtkcomm
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gtkcomm
PORTVERSION=	0.6.4
PORTREVISION=	6
CATEGORIES=	korean comms
MASTER_SITES=	http://download.kldp.net/gtkcomm/

MAINTAINER=	cjh@kr.freebsd.org
COMMENT=	Serial controlling software, with gtk+ widget

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USE_PERL5_BUILD=yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -pi -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
