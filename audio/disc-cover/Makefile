# New ports collection makefile for:    disc-cover
# Date created:         20 Jan 2002
# Whom:                 Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	disc-cover
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.liacs.nl/~jvhemert/disc-cover/download/stable/

MAINTAINER=	flynn@energyhq.homeip.net

BROKEN=		"audio/p5-FreeDB dependency doesn't exist"

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/FreeDB.pm:${PORTSDIR}/audio/p5-FreeDB \
		latex:${PORTSDIR}/print/latex \
		dvips:${PORTSDIR}/print/dvips \
		convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

MAN1=		disc-cover.1

post-patch:
	@${REINPLACE_CMD} -e 's@/etc/disc-cover.conf@${LOCALBASE}/etc/disc-cover.conf@g' ${WRKSRC}/disc-cover
	@${ECHO_CMD} "all:" > ${WRKSRC}/Makefile
	@${ECHO_CMD} >> ${WRKSRC}/Makefile
	@${ECHO_CMD} "install:" >> ${WRKSRC}/Makefile

# This port doesn't have a Makefile, and we need to fix some stuff (like the conf file name)

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/disc-cover ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/example.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/disc-cover.1 ${MANPREFIX}/man/man1
	@${ECHO_CMD}
	@${ECHO_CMD} "	############################################################"
	@${ECHO_CMD} "	You can set your preferences by editing the file ${PORTNAME}.conf.sample"
	@${ECHO_CMD} "	in ${PREFIX}/etc and renaming it to ${PORTNAME}.conf"
	@${ECHO_CMD} "	############################################################"
	@${ECHO_CMD}

.include <bsd.port.mk>
