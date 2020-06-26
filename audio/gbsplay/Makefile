# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	gbsplay
DISTVERSION=	0.0.94
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Emulates the sound hardware of the Nintendo Game Boy(TM)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		compiler:c++11-lib desktop-file-utils gmake localbase:ldflags \
		shared-mime-info
USE_CSTD=	gnu89

USE_GITHUB=	yes
GH_ACCOUNT=	mmitch

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--sysconfdir=${PREFIX}/etc \
			--without-xmmsplugin

MAKE_ENV+=	EXAMPLESDIR="${STAGEDIR}${EXAMPLESDIR}"

OPTIONS_DEFINE=		BASH_COMPLETIONS DOCS EXAMPLES NAS NLS
OPTIONS_DEFAULT=	BASH_COMPLETIONS
OPTIONS_SUB=		yes

BASH_COMPLETIONS_DESC=	Install bash completions

NAS_LIB_DEPENDS=	libaudio.so:audio/nas
NAS_CONFIGURE_ENABLE=	nas
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-i18n
NLS_LDFLAGS=		-lintl

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/\(gbsplayrc\)|${PREFIX}/etc/\1|" \
		${WRKSRC}/man/gbsplay.in.1 ${WRKSRC}/man/gbsplayrc.in.5

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/gbsplayrc_sample \
		${STAGEDIR}${PREFIX}/etc/gbsplayrc.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gbsplay \
		${STAGEDIR}${PREFIX}/bin/gbsinfo

post-install-BASH_COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/contrib/gbsplay.bashcompletion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}

.include <bsd.port.mk>
