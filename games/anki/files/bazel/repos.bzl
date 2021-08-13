# Definitions of local bazel repositories

def register_repos():
    "Register required dependency repos."

    # bazel
    #########
    native.local_repository(
	name = "bazel_skylib",
	path = "%%_MY_LOCALREPO%%/bzlskylib",
    )

    # rust
    ########
    native.local_repository(
	name = "rules_rust",
	path = "%%_MY_LOCALREPO%%/rules_rust",
    )

    # protobuf
    ############
    native.local_repository(
	name = "rules_proto",
	path = "%%_MY_LOCALREPO%%/rules_proto",
    )

    # python
    ##########
    native.local_repository(
	name = "rules_python",
	path = "%%_MY_LOCALREPO%%/rules_python",
    )

    # python pip
    ##############
    native.local_repository(
        name = "com_github_ali5h_rules_pip",
        path = "%%_MY_LOCALREPO%%/rules_pip",
    )

    # javascript
    ##############
    native.local_repository(
	name = "build_bazel_rules_nodejs",
	path = "%%_MY_LOCALREPO%%/rules_nodejs",
    )

    # esbuild-toolchain
    #####################
    native.local_repository(
	name = "esbuild_toolchain",
	path = "%%_MY_LOCALREPO%%/esbuild_toolchain",
    )

    # sass
    ########
    native.local_repository(
        name = "io_bazel_rules_sass",
	path = "%%_MY_LOCALREPO%%/rules_sass",
    )

    # i18n translation files
    ##########################
    native.local_repository(
        name = "rslib_ftl",
	path = "%%_MY_LOCALREPO%%/ftlrslib",
    )

    # i18n extra files
    ####################
    native.local_repository(
        name = "extra_ftl",
	path = "%%_MY_LOCALREPO%%/ftlextra",
    )

    # transitive dependency
    #########################
    native.local_repository(
        name = "rules_cc",
	path = "%%_MY_LOCALREPO%%/rules_cc",
    )

    # transitive dependency
    #########################
    native.local_repository(
        name = "rules_java",
	path = "%%_MY_LOCALREPO%%/rules_java",
    )

    # transitive dependency
    #########################
    native.local_repository(
        name = "build_bazel_rules_typescript",
        path = "%%_MY_LOCALREPO%%/rules_nodejs/third_party/github.com/bazelbuild/rules_typescript",
    )

    # stub pyqt5 repository
    #########################
    native.local_repository(
        name = "pyqt5",
	path = "%%_MY_LOCALREPO%%/pyqt5",
    )

    # provides node from ports
    ############################
    native.local_repository(
        name = "local_node",
	path = "%%_MY_LOCALREPO%%/local_node",
    )
