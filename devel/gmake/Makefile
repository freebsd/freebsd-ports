# Created by: jkh
# $FreeBSD$

PORTNAME=	gmake
PORTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNU/make
DISTNAME=	make-${PORTVERSION}

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU version of 'make' utility

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-prefix=g \
		--without-guile

USES=		cpe makeinfo tar:bzip2
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_ENABLE=	nls

CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"

INFO=		make

.include <bsd.port.mk>
