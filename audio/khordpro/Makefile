# New ports collection makefile for:	khordpro
# Date created:				June 8, 2001
# Whom:					Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	khordpro
PORTVERSION=	0.1
CATEGORIES=	audio kde
MASTER_SITES=	http://digilander.iol.it/merlim/khordpro/files/

MAINTAINER=	sethk@meowfishies.com

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_KDELIBS_VER=2

post-patch:
	@${PERL} -pi -e "s@-lqt @-lqt2 @g" ${WRKSRC}/khordpro/Makefile.in
	@${PERL} -pi -e "s@/usr/bin@${LOCALBASE}/bin@g" ${WRKSRC}/khordpro/cpm_html.cpp
	@${PERL} -pi -e "s@/usr/bin/perl@${PERL}@" ${WRKSRC}/cpm.pl
	@${PERL} -pi -e "s@-O2@${CFLAGS}@g" ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/khordpro/Makefile.in

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/cpm.pl ${PREFIX}/bin/cpm

.include <bsd.port.mk>
