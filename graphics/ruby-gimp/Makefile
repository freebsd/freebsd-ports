# New ports collection makefile for:	ruby-gimp
# Date created:		28 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	20010315
CATEGORIES=	graphics ruby
MASTER_SITES=	http://homepage1.nifty.com/susho/software/gimp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-snapshot-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	gimptool:${.CURDIR}/../gimp1
LIB_DEPENDS=	gimp.1:${.CURDIR}/../gimp1
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
INSTALL_TARGET=	site-install
PLIST_SUB=	X11BASE="${X11BASE}"

DOCS_EN=	ChangeLog \
		ENVIRONMENT \
		README \
		TODO
DOCS_JA=	doc/API.ja.html \
		doc/BUGS.ja \
		doc/MEMO.ja

#post-build:
#	cd ${WRKSRC}/embed && ${SETENV} CC='${CC}' \
#	CFLAGS='-I${RUBY_ARCHLIBDIR} -DMODULE_COMPILATION' \
#	LDFLAGS='-L${PREFIX}/lib -lruby' \
#	gimptool --build rubymod.c

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/plug-ins/*.rb ${X11BASE}/libexec/gimp/1.2/plug-ins/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
