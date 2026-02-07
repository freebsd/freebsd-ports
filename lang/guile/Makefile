PORTNAME=	guile-meta
PORTVERSION=	4
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Meta-port for the Guile interpreter
WWW=		http://www.gnu.org/software/guile/

LICENSE=	NA
LICENSE_COMB=	single
LICENSE_NAME=	Non applicable
LICENSE_TEXT=	No licenses are applicable to metaports
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# no flavors and no version specified, so that we get the default
# version as specified in DEFAULT_VERSIONS.
USES=		guile:run

NO_ARCH=	yes
NO_BUILD=	yes

# We don't provide a pkgconf or similar - this is purely a user
# convenience, and building should always be done against a specific
# version.
PLIST_FILES=	bin/guile bin/guild

do-install:
	for prog in guile guild; do \
		${LN} -sf $${prog}-${GUILE_VER} \
			${STAGEDIR}${PREFIX}/bin/$${prog}; \
	done

.include <bsd.port.mk>
