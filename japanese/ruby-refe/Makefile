# New ports collection makefile for:	rbbr
# Date created:		24 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	refe
PORTVERSION=	0.5.0
CATEGORIES=	japanese lang ruby
MASTER_SITES=	http://www.loveruby.net/archive/refe/ \
		http://www.ruby-lang.org/~rubikitch/refm/:refm \
		http://www.loveruby.net/archive/:extrefm
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ruby-refm.rd.gz:refm \
		extrefm.rd:extrefm
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	knu@FreeBSD.org

IGNOREFILES=	ruby-refm.rd.gz \
		extrefm.rd

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	ChangeLog \
		TODO
DOCS_JA=	README.ja

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

.if exists(${RUBY_ARCHLIBDIR}/gdbm.so)
RUN_DEPENDS+=	${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm

PLIST_SUB+=	WITH_GDBM="" WITH_DBM="@comment "
.else
PLIST_SUB+=	WITH_DBM="" WITH_GDBM="@comment "
.endif

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ruby-refm.rd.gz ${WRKSRC}/
	${GUNZIP_CMD} ${WRKSRC}/ruby-refm.rd.gz
	${CP} ${DISTDIR}/${DIST_SUBDIR}/extrefm.rd ${WRKSRC}/

post-patch:
	${RM} -f ${WRKSRC}/lib/refe/*.orig

post-install:
	cd ${WRKSRC}; ${PREFIX}/bin/mkrefe -ir ruby-refm.rd
	cd ${WRKSRC}; ${PREFIX}/bin/mkrefe -e extrefm.rd
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
