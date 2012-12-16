# New ports collection makefile for:	keitairc2
# Date created:		18 Jan 2008
# Whom:			Makoto Matsushita <matusita@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=		keitairc
PORTVERSION=		2.0
#PORTREVISION=		1
CATEGORIES=		irc
MASTER_SITES=		SFJP
MASTER_SITE_SUBDIR=	${PORTNAME}/47485
#DISTNAME=		keitairc-2.0

#PATCH_SITES=		http://home.jp.FreeBSD.org/~matusita/keitairc2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC proxy for mobilephone that have a web interface

RUN_DEPENDS=	p5-POE-Component-IRC>=0:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig

CONFLICTS=	keitairc-1.*
NO_BUILD=	yes
USE_PERL5=	yes

post-extract:
	${FIND} ${WRKSRC} -name .cvsignore | ${XARGS} ${RM} -rf

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM} -rf
	${REINPLACE_CMD} -i '' -e "s,^#!/usr/bin/perl$$,#!${PERL}," ${WRKSRC}/keitairc
	${REINPLACE_CMD} -i '' -e "s,/usr/share/keitairc/lib,${DATADIR}/lib,"  ${WRKSRC}/keitairc
	${REINPLACE_CMD} -i '' -e "s,__KEITAIRC_DATA_DIR__,${DATADIR}/lib,"  ${WRKSRC}/lib/Keitairc/Config.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keitairc ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for dir in doc etc lib
	${CP} -R ${WRKSRC}/${dir} ${DATADIR}
.endfor

.include <bsd.port.mk>
