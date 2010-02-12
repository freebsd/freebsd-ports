# New ports collection makefile for:	gauche
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gauche
PORTVERSION=	0.9	# Keep databases/gauche-gdbm in sync with this
CATEGORIES=	lang scheme
MASTER_SITES=	SF/${PORTNAME}/Gauche/
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

#INFOSECTION=	The Algorithmic Language Scheme

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads=${GAUCHE_THREADS} \
		--enable-multibyte=${GAUCHE_ENCODING} \
		--with-slib=${LOCALBASE}/share/slib \
		--with-iconv=${LOCALBASE}
PLIST_SUB=	VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}"

#		INFOSECTION="${INFOSECTION}"

USE_ICONV=	yes
USE_LDCONFIG=	yes

MAN1=		gosh.1 gauche-config.1

MAKE_JOBS_UNSAFE=yes

.if !defined(NOPORTDOCS)
INFO=		gauche-refe gauche-refj
.endif

.include <bsd.port.pre.mk>

.if (${ARCH} == "ia64") || (${ARCH} == "sparc64")
BROKEN=		Does not compile on ${ARCH}
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gosh
	${RM} -f ${PREFIX}/share/gauche/${PORTVERSION}/lib/slibcat
	${MKDIR} ${PREFIX}/share/gauche/site/lib/.packages
	${TOUCH} ${PREFIX}/share/gauche/site/lib/.packages/.keepme
	${TOUCH} ${PREFIX}/lib/gauche/site/${PORTVERSION}/${CONFIGURE_TARGET}/.keepme
	${MKDIR} ${PREFIX}/share/gauche/${PORTVERSION}/lib/.packages
	${TOUCH} ${PREFIX}/share/gauche/${PORTVERSION}/lib/.packages/.keepme
	${MKDIR} ${DOCSDIR}
	${TOUCH} ${DOCSDIR}/.keepme
	${MKDIR} ${EXAMPLESDIR}
	${TOUCH} ${EXAMPLESDIR}/.keepme
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/doc/*.info.gz ${WRKSRC}/doc/*.info-[1-7].gz ${PREFIX}/info/
.endif

.include <bsd.port.post.mk>
