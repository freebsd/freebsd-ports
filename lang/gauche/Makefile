# New ports collection makefile for:	gauche
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gauche
PORTVERSION=	0.6.6	# Keep databases/gauche-gdbm in sync with this
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Gauche-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org

# Choices are: "pthreads" and "no", but it seems that FreeBSD does not
# yet fully support threads with Boehm GC.
GAUCHE_THREADS?=	no
# Choices are: "utf-8", "euc-jp", "shift-jis" and "no"
GAUCHE_ENCODING?=	utf-8

INFOSECTION=	The Algorithmic Language Scheme

MAN1=		gosh.1 \
		gauche-config.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads=${GAUCHE_THREADS} \
		--enable-multibyte=${GAUCHE_ENCODING}
INSTALL_TARGET=	install-rpm
PLIST_SUB=	VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}" \
		INFOSECTION="${INFOSECTION}"

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gosh
	-${PREFIX}/bin/gosh -u slib -e "(require 'logical)" -e "(exit 0)" > /dev/null 2>&1
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${MANPREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/*.info ${PREFIX}/info/
.for info in gauche-refe.info gauche-refj.info
	install-info --section="${INFOSECTION}" ${WRKSRC}/doc/${info} ${PREFIX}/info/dir
.endfor
.endif

.include <bsd.port.mk>
