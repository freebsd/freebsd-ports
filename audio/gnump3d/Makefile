# Ports collection makefile for:	gnump3d
# Date created:			May 27, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gnump3d
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A streaming server for MP3, Ogg Vorbis, and other streamable audio files

RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		sox:${PORTSDIR}/audio/sox \
		oggenc:${PORTSDIR}/audio/vorbis-tools

USE_BZIP2=	yes
USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		gnump3d-index.1 gnump3d-top.1 gnump3d.1 gnump3d.conf.1

CONFDIR=	${PREFIX}/etc/${PORTNAME}
PERL_SITELIBDIR=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=	"You need at least perl 5.6.0. Do not use FreeBSD 4.x' system perl,\
	it's outdated. Install lang/perl5 and issue 'use.perl port'"
.endif

post-patch:
.for file in bin/gnump3d-index bin/gnump3d-top bin/gnump3d2 etc/gnump3d.conf \
	man/gnump3d.conf.1
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PERL_SITELIBDIR%%|${PERL_SITELIBDIR}|g' ${WRKSRC}/${file}
.endfor

do-install:
.for file in gnump3d-index gnump3d-top gnump3d2
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${PREFIX}/bin
.endfor
	${LN} -sf gnump3d2 ${PREFIX}/bin/gnump3d
.for file in gnump3d-index.1 gnump3d-top.1 gnump3d.1 gnump3d.conf.1
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor
	${MKDIR} ${PERL_SITELIBDIR}
	cd ${WRKSRC}/lib && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PERL_SITELIBDIR}
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/templates && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/mime.types ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/gnump3d.conf \
		${CONFDIR}/gnump3d.conf-default
.if !exists(${PREFIX}/etc/${PORTNAME}/gnump3d.conf)
	cd ${CONFDIR} && ${CP} gnump3d.conf-default gnump3d.conf
.endif
	${MKDIR} /var/log/${PORTNAME}

.include <bsd.port.post.mk>
