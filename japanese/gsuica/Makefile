# New ports collection makefile for:	gsuica
# Date created:				21 February 2010
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gsuica
PORTVERSION=	0.9.1
#PORTREVISION=	0
CATEGORIES=	japanese ruby
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GNOME SUICA Viewer

LICENSE=	GPLv2

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/pasori.so:${PORTSDIR}/devel/libpafe-ruby

USE_RUBY=	yes
RUBY_VER=	1.9

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=		yes
NO_BUILD=		yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,#! /usr/bin/ruby1.9.3,#!${RUBY},g' \
			  ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Fetch station code database
station-code-fetch:
	@(cd ${WRKDIR}; \
	  ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		-o StationCode.xls \
		http://www.denno.net/SFCardFan/sendexcel.php; \
		${FETCH_AFTER_ARGS} \
	  ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		${MASTER_SITES}station_code_conv.sh ${FETCH_AFTER_ARGS})

# Install station code database into ~/.gsuica/station_code
# BUILD_DEPENDS+=	nkf:${PORTSDIR}/japanese/nkf
# BUILD_DEPENDS+=	xlhtml:${PORTSDIR}/textproc/xlhtml
station-code-install:
	@(cd ${WRKDIR}; ${SH} station_code_conv.sh StationCode.xls)

.include <bsd.port.mk>
