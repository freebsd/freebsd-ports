# Created by: jkh
# $FreeBSD$

PORTNAME=	gmake
PORTVERSION=	3.82
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	make
DISTNAME=	make-${PORTVERSION}

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU version of 'make' utility

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-prefix=g

USES=		tar:bzip2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_ENABLE=	nls

CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"

INFO=		make

post-patch:
	@${REINPLACE_CMD} -e '/no-print-dir/s/@itemx/@item/' \
		${WRKSRC}/doc/make.texi
	@${RM} ${WRKSRC}/doc/make.info*

.include <bsd.port.mk>
