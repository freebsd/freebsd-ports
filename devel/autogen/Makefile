# ex:ts=8
# New ports collection makefile for:	autogen
# Date created:		Mar 11, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autogen
PORTVERSION=	5.3.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	AUTOCONF="${TRUE}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=	autogen.1 autoopts-config.1 columns.1 getdefs.1
MAN3=	optionFree.3 optionLoadLine.3 optionProcess.3 optionRestore.3 \
	optionSaveState.3 optionVersion.3

pre-patch:
	@${PERL} -pi -e 's|values.h ||g' ${WRKSRC}/snprintfv/configure

.include <bsd.port.mk>
