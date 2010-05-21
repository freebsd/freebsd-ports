# New ports collection makefile for:	gtar
# Date created:		Sa   6 Jun 1998 10:24:51 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	tar
PORTVERSION=	1.23
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU version of the traditional tape archiver

# only force dependencies for compressors that have a single-letter option
#RUN_DEPENDS=	# see below

INFO=		tar

USE_AUTOTOOLS=	autoconf:262:env	# autom4te
USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--program-prefix=g \
		--disable-silent-rules
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib ${LDSTATIC}' \
		DEFAULT_ARCHIVE=/dev/sa0 \
		DEFAULT_RMT_COMMAND=/etc/rmt

.if defined(WANT_STATIC)
LDSTATIC=	-static
MAKE_ARGS+=	LIBINTL='$$(LTLIBINTL)' LIBICONV='$$(LTLIBICONV)'
.else
LDSTATIC=
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
RUN_DEPENDS+=	xz:${PORTSDIR}/archivers/xz
.endif

.include <bsd.port.post.mk>
