# $FreeBSD$
# To be used by modules using Module::Build

.if ${PORTNAME} != Module-Build
BUILD_DEPENDS+=		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build
.endif

CONFIGURE_ARGS+=	install_path=lib="${PREFIX}/${SITE_PERL:S|^${LOCALBASE}/||}" \
			install_path=arch="${PREFIX}/${SITE_PERL:S|^${LOCALBASE}/||}/${PERL_ARCH}" \
			install_path=script="${PREFIX}/bin" \
			install_path=bin="${PREFIX}/bin" \
			install_path=libdoc="${MAN3PREFIX}/man/man3" \
			install_path=bindoc="${MAN1PREFIX}/man/man1"

