# New ports collection makefile for:	koffice-i18n
# Date created:		15 December 2001
# Whom:			SASAKI Katuhiro <sahiro@crest.ocn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.1.1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	sahiro@crest.ocn.ne.jp

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	koshell:${PORTSDIR}/editors/koffice

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST=		${WRKDIR}/PLIST
SCRIPTS_ENV+=	PLIST=${PLIST}

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -fr ${WRKSRC}/nb ${WRKSRC}/nn

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/Configure

.include <bsd.port.post.mk>
