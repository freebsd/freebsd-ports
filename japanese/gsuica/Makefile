# New ports collection makefile for:	gsuica
# Date created:				21 February 2010
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gsuica
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	japanese ruby
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GNOME SUICA Viewer

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2 \
		${RUBY_SITEARCHLIBDIR}/pasori.so:${PORTSDIR}/devel/libpafe-ruby

USE_RUBY=		yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=		yes
NO_BUILD=		yes

PLIST_FILES=	bin/${PORTNAME}

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
