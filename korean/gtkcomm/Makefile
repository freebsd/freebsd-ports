# New ports collection makefile for:	gtkcomm
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gtkcomm
PORTVERSION=	0.8.1
CATEGORIES=	korean comms
MASTER_SITES=	http://kldp.net/frs/download.php/480/

MAINTAINER=	ports@freebsd.org
COMMENT=	Serial controlling software, with gtk+ widget

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USE_PERL5_BUILD=yes
USE_GNOME=	glib20 gtk20
GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -pi -e 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
