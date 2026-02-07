import financedatabase as fd

# Initialize the Equities database
equities = fd.Equities()
print(f"equities={equities}")

# Obtain all countries from the database
equities_countries = equities.options('country')
print(f"equities_countries={equities_countries}")

# Obtain all sectors from the database
equities_sectors = equities.options('sector')
print(f"equities_sectors={equities_sectors}")

# Obtain all industry groups from the database
equities_industry_groups = equities.options('industry_group')
print(f"equities_industry_groups={equities_industry_groups}")

# Obtain all industries from a country from the database
equities_germany_industries = equities.options('industry', country='Germany')
print(f"equities_germany_industries={equities_germany_industries}")

# Obtain a selection from the database
equities_united_states = equities.select(country="United States")
print(f"equities_united_states={equities_united_states}")

# Obtain a detailed selection from the database
equities_usa_consumer_electronics = equities.select(country="United States", industry="Consumer Electronics")
print(f"equities_usa_consumer_electronics={equities_usa_consumer_electronics}")

# Search specific fields from the database
equities_uk_biotech = equities.search(country='United Kingdom', summary='biotech', exchange='LSE')
print(f"equities_uk_biotech={equities_uk_biotech}")
