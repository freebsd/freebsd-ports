# New ports collection makefile for:	gauche
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gauche
PORTVERSION=	0.8.1	# Keep databases/gauche-gdbm in sync with this
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Gauche-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org
COMMENT=	Scheme script interpreter with multibyte character handling

# Choices are: "pthreads" and "no", but it seems that FreeBSD does not
# yet fully support threads with Boehm GC.
GAUCHE_THREADS?=	no
# Choices are: "utf-8", "euc-jp", "shift-jis" and "no"
GAUCHE_ENCODING?=	utf-8

# breaks in ext/uvecor.c on some locales
MAKE_ENV=	LANG=C

INFOSECTION=	The Algorithmic Language Scheme

MAN1=		gosh.1 \
		gauche-config.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads=${GAUCHE_THREADS} \
		--enable-multibyte=${GAUCHE_ENCODING} \
		--with-slib=${LOCALBASE}/share/slib \
		--with-iconv=${LOCALBASE}
PLIST_SUB=	VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}" \
		INFOSECTION="${INFOSECTION}"
USE_ICONV=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
INFO=		gauche-refe gauche-refj

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		"Does not compile on !i386 and !alpha (due to included boehm-gc)"
.endif

post-build:
	${REINPLACE_CMD} 's/gauche-refj.  info/gauche-refj.info/' ${WRKSRC}/doc/gauche-refj.info

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gosh
	${RM} -f ${PREFIX}/share/gauche/${PORTVERSION}/lib/slibcat
	${TOUCH} ${PREFIX}/share/gauche/site/lib/.keepme
	${TOUCH} ${PREFIX}/lib/gauche/site/${PORTVERSION}/${CONFIGURE_TARGET}/.keepme

.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/*.info ${PREFIX}/info/
.for info in ${INFO}
	install-info --section="${INFOSECTION}" ${WRKSRC}/doc/${info}.info ${PREFIX}/info/dir
.endfor
.endif

.include <bsd.port.post.mk>
