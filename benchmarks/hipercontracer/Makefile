PORTNAME=	hipercontracer
DISTVERSION=	2.1.1
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.nntb.no/~dreibh/hipercontracer/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	High-Performance Connectivity Tracer (HiPerConTracer)
WWW=		https://www.nntb.no/~dreibh/hipercontracer/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_log.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libinotify.so:devel/libinotify
RUN_DEPENDS=	getopt>=0:misc/getopt

USES=		cmake compiler:c++20-lang desktop-file-utils python \
		shared-mime-info shebangfix ssl tar:xz
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/results-examples/r-install-dependencies \
		src/results-examples/r-ping-example \
		src/results-examples/r-traceroute-example \
		src/TestDB/generate-test-certificates

# Work-around for build issue on ARM (https://bugs.freebsd.org/285706):
MAKE_ENV=	OMP_NUM_THREADS=1

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		COLLECTOR DBEAVERTOOLS DBSHELL ICONS IMPMARIADB \
			IMPMONGO IMPORTER IMPPGSQL NODE QUERYTOOL RESULTSTOOL \
			RTUNNEL SYNC TRIGGER UDPECHO VIEWERTOOL
OPTIONS_DEFAULT=	COLLECTOR DBEAVERTOOLS DBSHELL ICONS IMPMARIADB \
			IMPMONGO IMPORTER IMPPGSQL NODE QUERYTOOL RESULTSTOOL \
			RTUNNEL SYNC TRIGGER UDPECHO VIEWERTOOL
COLLECTOR_DESC=		Build HiPerConTracer Collector Tools
DBEAVERTOOLS_DESC=	Build DBeaver Tools
DBSHELL_DESC=		Build DBShell
ICONS_DESC=		Build Icons and Logo Files
IMPMARIADB_DESC=	Enable MariaDB/MySQL support for HiPerConTracer Importer Tool
IMPMONGO_DESC=		Enable MongoDB support for HiPerConTracer Importer Tool
IMPORTER_DESC=		Build HiPerConTracer Importer Tool
IMPPGSQL_DESC=		Enable PostgreSQL support for HiPerConTracer Importer Tool
NODE_DESC=		Build HiPerConTracer Node Tools
QUERYTOOL_DESC=		Build HiPerConTracer Query Tool
RESULTSTOOL_DESC=	Build HiPerConTracer Results Tool
RTUNNEL_DESC=		Build HiPerConTracer Reverse Tunnel Tool
SYNC_DESC=		Build HiPerConTracer Synchronisation Tool
TRIGGER_DESC=		Build HiPerConTracer Trigger Tool
UDPECHO_DESC=		Build UDP Echo Server
VIEWERTOOL_DESC=	Build HiPerConTracer Viewer Tool

COLLECTOR_CMAKE_BOOL=		WITH_COLLECTOR
DBEAVERTOOLS_CMAKE_BOOL=	WITH_DBEAVER_TOOLS
DBSHELL_CMAKE_BOOL=		WITH_DBSHELL
ICONS_BUILD_DEPENDS=		gm:graphics/GraphicsMagick \
				gs:print/ghostscript10 \
				pdf2svg:graphics/pdf2svg
ICONS_CMAKE_BOOL=		WITH_ICONS
IMPMARIADB_LIB_DEPENDS=		libmariadb.so:databases/mariadb106-client
IMPMARIADB_CMAKE_BOOL=		ENABLE_BACKEND_MARIADB
IMPMONGO_LIB_DEPENDS=		libbson-1.0.so:devel/libbson \
				libmongoc-1.0.so:devel/mongo-c-driver
IMPMONGO_CMAKE_BOOL=		ENABLE_BACKEND_MONGODB
IMPORTER_CMAKE_BOOL=		WITH_IMPORTER
IMPPGSQL_LIB_DEPENDS=		libpqxx.so:databases/postgresql-libpqxx
IMPPGSQL_CMAKE_BOOL=		ENABLE_BACKEND_POSTGRESQL
NODE_CMAKE_BOOL=		WITH_NODE
QUERYTOOL_CMAKE_BOOL=		WITH_QUERY
RESULTSTOOL_CMAKE_BOOL=		WITH_RESULTS
RTUNNEL_CMAKE_BOOL=		WITH_RTUNNEL
SYNC_CMAKE_BOOL=		WITH_SYNC
TRIGGER_CMAKE_BOOL=		WITH_TRIGGER
UDPECHO_CMAKE_BOOL=		WITH_UDP_ECHO_SERVER
VIEWERTOOL_CMAKE_BOOL=		WITH_VIEWER

.include <bsd.port.mk>
