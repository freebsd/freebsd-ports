# New ports collection makefile for:	global
# Date created:		20 June 2000
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	global
PORTVERSION=	4.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rui@ruilopes.com
COMMENT=	A source code tag system

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		gctags.1 global.1 gozilla.1 gtags.1 htags.1
INFO=		global

post-install:
	install-info ${PREFIX}/info/global.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/global
.for file in AUTHORS COPYING ChangeLog FAQ INSTALL LICENSE NEWS README \
		THANKS
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/global
.endfor
.endif

.include <bsd.port.mk>
