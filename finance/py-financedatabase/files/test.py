import financedatabase as fd

# Obtain all countries from the database
equities_countries = fd.show_options('equities', 'countries')
print(f"equities_countries={equities_countries}")

# Obtain all sectors from the database
equities_sectors = fd.show_options('equities', 'sectors')
print(f"equities_sectors={equities_sectors}")

# Obtain all industries from the database
equities_industries = fd.show_options('equities', 'industries')
print(f"equities_industries={equities_industries}")

# Obtain all countries + sectors + industries from the database
equities_all_categories = fd.show_options('equities')
print(f"equities_all_categories={equities_all_categories}")
