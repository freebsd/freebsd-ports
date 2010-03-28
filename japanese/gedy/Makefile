# New ports collection makefile for:	gedy
# Date created:				21 February 2010
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gedy
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	japanese ruby
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GNOME Edy Viewer

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2 \
		${RUBY_SITEARCHLIBDIR}/pasori.so:${PORTSDIR}/devel/libpafe-ruby

USE_RUBY=		yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=		yes
NO_BUILD=		yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
